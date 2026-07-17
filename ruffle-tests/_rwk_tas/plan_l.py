# plan_l — plan_h's proven front half + lip-park through alien-3's turn,
# late step-off past both kill pockets, throttle-follow to the J.
# Evidence: h/i/j parked the lip (world ~309) at 3-12px from alien-3 with
# no death -> its right end stops short of the lip / kill range is small.
# Floor alien clears the landing pocket (<=294) after ~t1116.
click(plan, 158, 303, 255)
hold(plan, "RIGHT", 285, 332)    # off spawn ledge -> shelf-1
hold(plan, "LEFT", 336, 366)     # to x=13, drop to shelf-2 (park)
hold(plan, "LEFT", 897, 918)     # drop -> platform-1, land ~t920
hold(plan, "RIGHT", 923, 978)    # cross p1, fall to p2, cross p2 to the lip
hold(plan, "RIGHT", 982, 984)    # tap to the lip (world ~309), park
# ... alien-3 right-end turn ~t1064 passes (the gamble) ...
hold(plan, "RIGHT", 1108, 1111)  # step off ~t1112
hold(plan, "LEFT", 1128, 1141)   # land ~306 ~t1127; close gap 19 -> ~14
t = 1145
for _ in range(14):              # throttle-follow the floor alien (8 on/5 off)
    hold(plan, "LEFT", t, t + 8)
    t += 13
hold(plan, "LEFT", 1332, 1340)   # settle onto the J (world ~168)
press(plan, "X", 1372)           # jump test after pickup
press(plan, "X", 1405)           # second jump test
TOTAL = 1480
