click(plan, 158, 303, 255)
hold(plan, "RIGHT", 285, 332)   # off spawn ledge -> shelf-1
hold(plan, "LEFT", 336, 366)    # to x=13, drop to shelf-2 (safe), park
# wait out alien-2's rightward sweep on shelf-2 until ~t625
hold(plan, "LEFT", 625, 646)    # drop at x=11 onto platform-1 behind alien-2
hold(plan, "RIGHT", 652, 700)   # cross right, off edge x=13.9 -> platform-2
hold(plan, "RIGHT", 704, 748)   # across platform-2, off right edge -> J chamber
hold(plan, "LEFT", 758, 838)    # walk left along chamber floor to the J
press(plan, "Z", 860)           # test jump after pickup
TOTAL = 920
