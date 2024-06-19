// Created on: Jun 24, 2018
//       Author: Tri Nguyen
// Copyright (c) 2018 The Pigeon Core developers
// Copyright (c) 2020-2024 The Raptoreum developers
// Copyright (c) 2024 The Hootchain developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <devfee_payment.h>
#include <rpc/server.h>
#include <util/system.h>

#include <boost/foreach.hpp>
#include <key_io.h>

CAmount DevfeePayment::getDevfeePaymentAmount(int blockHeight, CAmount blockSubsidy) {
	  if (blockHeight <= startBlock){
		    return 0;
	  }
	  for(int i = 0; i < rewardStructures.size(); i++) {
		    DevfeeRewardStructure rewardStructure = rewardStructures[i];
		    if(rewardStructure.blockHeight == INT_MAX || blockHeight <= rewardStructure.blockHeight) {
			      return blockSubsidy / rewardStructure.rewardDivisor;
		    }
	  }
	  return 0;
}

void DevfeePayment::FillDevfeePayment(CMutableTransaction& txNew, int nBlockHeight, CAmount blockSubsidy, CTxOut& txoutDevfeeRet) {
    // make sure it's not filled yet
    CAmount devfeePayment = getDevfeePaymentAmount(nBlockHeight, blockSubsidy);
    if(devfeePayment == 0) {
        LogPrintf("DevfeePayment::FillDevfeePayment -- Devfee payment has not started\n");
        return;
    }
    txoutDevfeeRet = CTxOut();
	  // fill payee with the devfee address
	  CTxDestination devfeeAddr = DecodeDestination(devfeeAddress);
	  if(!IsValidDestination(devfeeAddr)) {
	      throw JSONRPCError(RPC_INVALID_ADDRESS_OR_KEY, strprintf("Invalid Hootchain Devfee Address: %s", devfeeAddress.c_str()));
    }
	  CScript payee = GetScriptForDestination(devfeeAddr);
    // GET DEVFEE PAYMENT VARIABLES SETUP

    // split reward between miner ...
    txNew.vout[0].nValue -= devfeePayment;
    txoutDevfeeRet = CTxOut(devfeePayment, payee);
    txNew.vout.push_back(txoutDevfeeRet);
    LogPrintf("DevfeePayment::FillDevfeePayment -- Devfee payment %lld to %s\n", devfeePayment, devfeeAddress.c_str());
}

bool DevfeePayment::IsBlockPayeeValid(const CTransaction& txNew, const int height, const CAmount blockSubsidy) {
	  // fill payee with the devfee address
	  CScript payee = GetScriptForDestination(DecodeDestination(devfeeAddress));
	  const CAmount devfeeReward = getDevfeePaymentAmount(height, blockSubsidy);
	  BOOST_FOREACH(const CTxOut& out, txNew.vout) {
		    if(out.scriptPubKey == payee && out.nValue >= devfeeReward) {
			      return true;
		    }
	  }

	  return false;
}