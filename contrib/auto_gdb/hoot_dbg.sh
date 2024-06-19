#!/usr/bin/env bash
# Copyright (c) 2018-2023 The Dash Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.
# use testnet settings,  if you need mainnet,  use ~/.hootcore/hootd.pid file instead
export LC_ALL=C

hoot_pid=$(<~/.hootcore/testnet3/hootd.pid)
sudo gdb -batch -ex "source debug.gdb" hootd ${hoot_pid}
