# plan_h — descent via platform-2's LEFT TIP (alien-3 never patrols left of
# p1-cam ~445; the tip 415-445 is a safe transit pad). Chain:
#  - LEFT-drop to platform-1 at t~920 (alien-2 at ~257 moving right, 38px
#    behind our 295 landing — we outrun it right).
#  - Cross to p1's right edge, then TAP off with no momentum -> land the tip
#    (~1008; alien-3 at ~540+, far right, moving right).
#  - Immediately walk off the tip's LEFT edge -> chamber floor world ~205
#    at t~1055 (floor alien at ~302, its right-end turn t1059).
#  - Walk left to the J (world 168), pick up ~1100 (floor alien returns to
#    the J zone only at ~t1222). Jump tests, end before contact.
click(plan, 158, 303, 255)
hold(plan, "RIGHT", 285, 332)   # off spawn ledge -> shelf-1
hold(plan, "LEFT", 336, 366)    # to x=13, drop to shelf-2 (park)
hold(plan, "LEFT", 897, 918)    # drop -> platform-1, land ~t920
hold(plan, "RIGHT", 923, 978)   # cross 295 -> ~400 (edge at 410)
hold(plan, "RIGHT", 982, 984)   # tap: inch to the lip
hold(plan, "RIGHT", 988, 990)   # tap: step off ~992, no momentum
hold(plan, "LEFT", 1017, 1034)  # on the tip: walk off its left edge
hold(plan, "LEFT", 1060, 1100)  # floor world ~205 -> J at 168
press(plan, "X", 1130)          # jump test after pickup
press(plan, "X", 1165)          # second jump test
TOTAL = 1220
