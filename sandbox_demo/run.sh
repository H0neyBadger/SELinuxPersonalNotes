#!/bin/bash
set -euxo pipefail

BACKDOOR="./backdoor"

mkdir -p ./sandbox/tmp
sudo gcc -o $BACKDOOR backdoor.c
sudo chown root:root ./backdoor
sudo chmod 4755 $BACKDOOR
sudo chcon -t sandbox_net_t $BACKDOOR
runcon -t sandbox_net_t $BACKDOOR

#sandbox -M -H "./sandbox" -T "./sandbox/tmp" -t sandbox_net_t "$BACKDOOR"
