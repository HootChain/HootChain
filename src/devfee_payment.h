// Created on: Jun 24, 2018
//       Author: Tri Nguyen
// Copyright (c) 2020-2024 The Raptoreum developers
// Copyright (c) 2024 The Hootchain developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SRC_DEVFEE_PAYMENT_H_
#define SRC_DEVFEE_PAYMENT_H_
#include <string>
#include <amount.h>
#include <primitives/transaction.h>
#include <vector>

static const std::string DEFAULT_DEVFEE_ADDRESS = "hJ4cyyGooZHcZkEwTLkL8JYb8C8gYouvPy";

struct DevfeeRewardStructure {
	  int blockHeight;
	  double rewardDivisor;
};

class DevfeePayment {
public:
	  DevfeePayment(std::vector<DevfeeRewardStructure> rewardStructures = {}, int startBlock = 0, const std::string &address = DEFAULT_DEVFEE_ADDRESS) {
        this->devfeeAddress = address;
        this->startBlock = startBlock;
        this->rewardStructures = rewardStructures;
    }
    ~DevfeePayment(){};
    CAmount getDevfeePaymentAmount(int blockHeight, CAmount blockSubsidy);
    void FillDevfeePayment(CMutableTransaction& txNew, int nBlockHeight, CAmount blockSubsidy, CTxOut& txoutDevfeeRet);
    bool IsBlockPayeeValid(const CTransaction& txNew, const int height, const CAmount blockSubsidy);
    int getStartBlock() {return this->startBlock;}
private:
    std::string devfeeAddress;
    int startBlock;
    std::vector<DevfeeRewardStructure> rewardStructures;
};

#endif /* SRC_DEVFEE_PAYMENT_H_ */
