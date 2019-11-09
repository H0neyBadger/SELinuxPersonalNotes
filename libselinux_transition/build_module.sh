#!/bin/bash
set -exuo pipefail

# checkmodule -M -m -o ./test_setexeccon.mod ./test_setexeccon.te
# semodule_package -o ./test_setexeccon.pp -m ./test_setexeccon.mod
make -f /usr/share/selinux/devel/Makefile ./test_setexeccon.pp
# as privileged user 
sudo semodule -i ./test_setexeccon.pp
