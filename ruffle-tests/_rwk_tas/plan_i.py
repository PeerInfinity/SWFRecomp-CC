# plan_i — descent to the J with a throttle-follow ending.
# plan_h autopsy: step-off ~t992 -> floor landing ~1014 at world ~310 hit the
# floor alien's right-end turnaround (world ~305 @ t1059, kill range ~14
# world px). Fix: park on the platform edge until t1058 (alien-2 reaches the
# edge ~t1070 — leave before), land ~t1080 with the floor alien at ~291
# moving LEFT (gap ~19), brief full-speed close, then duty-cycle LEFT
# (8 on / 5 off ~= 0.65 world px/tick ~= its 0.667) trailing it to the J;
# it passes the J ~t1264, we settle on the J ~t1290. Jump tests after.
click(plan, 158, 303, 255)
hold(plan, "RIGHT", 285, 332)   # off spawn ledge -> shelf-1
hold(plan, "LEFT", 336, 366)    # to x=13, drop to shelf-2 (park)
hold(plan, "LEFT", 897, 918)    # drop -> platform, land ~t920
hold(plan, "RIGHT", 923, 978)   # cross toward the right edge (world ~308)
hold(plan, "RIGHT", 982, 984)   # tap to the lip, stay ON the edge
press(plan, "DOWN", 990)        # no-op safety (keeps timeline readable)
hold(plan, "RIGHT", 1054, 1057) # step off ~t1058 (before alien-2 ~t1070)
hold(plan, "LEFT", 1085, 1097)  # floor ~t1080: close 19 -> ~14 gap
t = 1100
for _ in range(14):             # throttle-follow: 8 on / 5 off
    hold(plan, "LEFT", t, t + 8)
    t += 13
hold(plan, "LEFT", 1285, 1300)  # settle onto the J (world 168)
press(plan, "X", 1330)          # jump test after pickup
press(plan, "X", 1365)          # second jump test
TOTAL = 1450
