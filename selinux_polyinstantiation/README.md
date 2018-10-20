Selinux Polyinstantiation 
=========

Simple selinux polyinstantiation namespace config
* https://access.redhat.com/documentation/en-us/red_hat_enterprise_linux/7/html/selinux_users_and_administrators_guide/mls
* https://access.redhat.com/blogs/766093/posts/3169121 

Requirements
------------

dnf

Role Variables
--------------

* se_type: "mls" or "targeted"
* ns_exclude: 

Dependencies
------------


Example Playbook
----------------


    - hosts: servers
      roles:
         - { role: username.rolename, x: 42 }

License
-------

BSD

Author Information
------------------

