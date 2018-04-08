# SELinuxPersonalNotes
Every modules or snippets are intended for personal use.
Do not try to run it on a production environment.


List policy 
``` 
sesearch --allow -C --target=cifs_t --class=file --perm=create
sesearch --allow -C --target=cifs_t --class=dir --perm=remove_name
```

Compile
```
make -f /usr/share/selinux/devel/Makefile privadmin.pp
semodule -i privadmin.pp
ausearch -m avc -ts recent
```

log dontaudit policy
```
semodule --disable_dontaudit --build
semodule --build
```

Install
```
yum install selinux-policy-devel setools-console policycoreutils-python policycoreutils-newrole
yum install policycoreutils-sandbox selinux-policy-sandbox
yum install selinux-policy-mls
````

Config
```
ls -Z $(tty)
vim /etc/selinux/mls/contexts/securetty_types
vim /etc/selinux/mls/setrans.conf
```

Services
```
systemctl enable mcstransd
# vi /etc/selinux/targeted/setrans.conf
# systemctl disable abrtd
```

Run sandbox
```
sandbox -M -H "./sandbox/" -T "/tmp/" -t sandbox_net_t "./test"
```
