Resources:
https://sysprog21.github.io/lkmpg/
https://tldp.org/LDP/lkmpg/2.4/html/x354.htm
https://www.kernel.org/doc/html/next/core-api/printk-basics.html


If so, how to fix the error (5pts), with the makefile I had to remove unnecessary spaces to make the makefile work.
Also had to install elfutils-libelf-devel as libelf-dev did not exist.


Part 1:
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

Part 2:
==== OUTPUT FROM dmesg -T | tail ====
[root@mycentos part2]# dmesg -T | tail State: 1
[Sat Mar 16 10:59:29 2024] Process: sshd PID: 1045 State: 1
[Sat Mar 16 10:59:29 2024] Process: systems PID: 1 State: 1
[Sat Mar 16 10:59:29 2024] Process: swapper/0 PID: 0 State: 0
[root@mycentos part2]# rmmod part2
[root@mycentos part2]# dmesg -T | tail
[Sat Mar 16 10:59:28 2024] Process: sshd PID: 1045 State: 1
[Sat Mar 16 10:59:28 2024] Process: systems PID: 1 State: 1
[Sat Mar 16 10:59:28 2024] Process: swapper/0 PID: 0 State: 0
[Sat Mar 16 11:00:18 2024] LEAVING THE PART 2 MODULE!
==== OUTPUT FROM dmesg -T | tail ====

Part 3:
==== OUTPUT FROM dmesg -T | tail ====
[root@mycentos part3]# pgrep bash
4608
[root@mycentos part3]# insmod part3.ko target_pid=4608
[root@mycentos part3]# dmesg -T | tail
[Sat Mar 16 11:43:25 2024] Process Name: sshd
[Sat Mar 16 11:43:25 2024] PID: 4600
[Sat Mar 16 11:43:25 2024] Process State: 1
[Sat Mar 16 11:43:25 2024] Process Name: sshd
[Sat Mar 16 11:43:25 2024] PID: 1045
[Sat Mar 16 11:43:25 2024] Process State: 1
[Sat Mar 16 11:43:25 2024] Process Name: systemd
[Sat Mar 16 11:43:25 2024] PID: 1
[Sat Mar 16 11:43:25 2024] Process State: 1
[Sat Mar 16 11:43:25 2024] Process: swapper/0, PID: 0, State: 0
[root@mycentos part3]# rmmod part3
[root@mycentos part3]# dmesg -T | tail
[Sat Mar 16 11:43:25 2024] PID: 4600
[Sat Mar 16 11:43:25 2024] Process State: 1
[Sat Mar 16 11:43:25 2024] Process Name: sshd
[Sat Mar 16 11:43:25 2024] PID: 1045
[Sat Mar 16 11:43:25 2024] Process State: 1
[Sat Mar 16 11:43:25 2024] Process Name: systemd
[Sat Mar 16 11:43:25 2024] PID: 1
[Sat Mar 16 11:43:25 2024] Process State: 1
[Sat Mar 16 11:43:25 2024] Process: swapper/0, PID: 0, State: 0
[Sat Mar 16 11:44:43 2024] GOODBYE FROM PART 3!
==== OUTPUT FROM dmesg -T | tail ====
