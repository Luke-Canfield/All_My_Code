#!/bin/bash

# Rule #1
sudo iptables -F
sudo iptables -X

# Rule #2
sudo iptables -A INPUT -s 67.199.248.12 -j ACCEPT

# Rule #3
sudo iptables -t nat -A POSTROUTING -o eth0 -j MASQUERADE

# Rule #4
sudo iptables -A INPUT -p tcp --tcp-flags ALL NONE -j DROP
sudo iptables -A INPUT -p tcp --tcp-flags ALL ALL -j DROP

# Rule #5
sudo iptables -A INPUT -p tcp --syn -m limit --limit 1/s --limit-burst 500 -j ACCEPT

# Rule #6
sudo iptables -A INPUT -i lo -j ACCEPT
sudo iptables -A OUTPUT -o lo -j ACCEPT

# Rule #7
sudo iptables -t nat -A PREROUTING -p tcp --dport 8888 -j DNAT --to-destination :25565

# Rule #8
sudo iptables -A OUTPUT -p tcp --dport 22 -d 128.46.104.20 -m state --state NEW,ESTABLISHED -j ACCEPT
sudo iptables -A INPUT -p tcp --sport 22 -s 128.46.104.20 -m state --state NEW,ESTABLISHED -j ACCEPT

# Rule #9
sudo iptables -P INPUT DROP
sudo iptables -P FORWARD DROP
sudo iptables -P OUTPUT DROP


