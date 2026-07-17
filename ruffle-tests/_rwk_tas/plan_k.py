# plan_k — descent shifted one alien-2 cycle later; momentum step-off.
# plan_i/j autopsy: fall is ~15 ticks; the t~1058 step-off (pinned by
# alien-2's t~1070 lip visit) lands at t~1073 exactly on the floor alien
# (right end >=315, turn ~t1080). One cycle later everything clears:
#  - LEFT-drop lands p1 ~t1203: alien-2 turned at its left end t~1194,
#    ~80px behind, chases at 1.33 vs our 2.1 (never catches).
#  - RIGHT straight off the lip ~t1266 with momentum -> land world ~316
#    at ~t1281; floor alien at ~183 moving LEFT (133px clear, its next
#    right-end visit ~t1758).
#  - Walk LEFT to the J (168): it stays ahead (gap closes 132->~78).
#    Settle ~t1425; floor alien turns at 79 ~t1438, returns to the J zone
#    ~t1592 — pickup + jump tests well before.
click(plan, 158, 303, 255)
hold(plan, "RIGHT", 285, 332)   # off spawn ledge -> shelf-1
hold(plan, "LEFT", 336, 366)    # to x=13, drop to shelf-2 (park)
hold(plan, "LEFT", 1180, 1201)  # drop -> platform, land ~t1203
hold(plan, "RIGHT", 1208, 1266) # cross and run straight off the right edge
hold(plan, "LEFT", 1290, 1428)  # land ~316 ~t1281; walk to the J at 168
press(plan, "X", 1455)          # jump test after pickup
press(plan, "X", 1490)          # second jump test
TOTAL = 1560
