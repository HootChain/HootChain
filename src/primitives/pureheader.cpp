// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "primitives/pureheader.h"

#include "chainparams.h"
#include "hash.h"

void CPureBlockHeader::SetBaseVersion(int32_t nBaseVersion, int32_t nChainId)
{
    assert(nBaseVersion >= 1 && nBaseVersion < VERSION_AUXPOW);
    assert(!IsAuxpow());
    nVersion = nBaseVersion | (nChainId * VERSION_CHAIN_START);
}

uint256 CPureBlockHeader::GetHash() const
{
    return GetPoWHash();
}

uint256 CPureBlockHeader::GetPoWHash() const
{
    std::vector<unsigned char> vch(80);
    CVectorWriter ss(SER_GETHASH, PROTOCOL_VERSION, vch, 0);
    ss << *this;
    return HashX11((const char *)vch.data(), (const char *)vch.data() + vch.size());
}