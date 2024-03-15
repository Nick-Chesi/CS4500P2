If so, how to fix the error (5pts), with the makefile I had to remove unnecessary spaces to make the makefile work.
Also had to install elfutils-libelf-devel as libelf-dev did not exist.


==== OUTPUT FROM dmesg -T | tail ====
[Thu Mar 14 19:57:44 2024] ip_set: protocol 7
[Thu Mar 14 19:57:45 2024] nf_conntrack version 0.5.0 (16384 buckets, 65536 max)
[Thu Mar 14 19:57:45 2024] bridge: filtering via arp/ip/ip6tables is no longer available by default. Update your scripts to load br_netfilter if you need this.
[Thu Mar 14 19:57:46 2024] IPv6: ADDRCONF(NETDEV_UP): ens192: link is not ready
[Thu Mar 14 19:57:46 2024] vmxnet3 0000:0b:00.0 ens192: intr type 3, mode 0, 2 vectors allocated
[Thu Mar 14 19:57:46 2024] vmxnet3 0000:0b:00.0 ens192: NIC Link is Up 10000 Mbps
[Fri Mar 15 16:08:05 2024] hello: loading out-of-tree module taints kernel.
[Fri Mar 15 16:08:05 2024] hello: module verification failed: signature and/or required key missing - tainting kernel
[Fri Mar 15 16:08:05 2024] HELLO WORLD!
[Fri Mar 15 16:08:28 2024] GOODBYE WORLD!
==== OUTPUT FROM dmesg -T | tail ====
