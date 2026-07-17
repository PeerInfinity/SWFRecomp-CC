# plan_f — full descent to the J, corrected physics + phases (RWK-3).
# Measured: player max walk ~1.05 world px/tick (NOT 4x alien); alien-2
# (platform-1) left-end turns t877/t1194, right-end t1035 (period 317);
# alien-3 (platform-2) left-end t936/t1192, right-end t1064 (period 256);
# floor alien right-end turn ~t1059 (period ~678, world 79<->305).
# Line: drop to platform-1 at t1131 (alien-2 at ~282 moving left/away);
# cross immediately, land platform-2 ~t1191 as alien-3 turns at its left
# end BEHIND us; cross to the right edge (it can't catch us at 1.33 vs
# 2.1 screen px/tick); fall to chamber floor ~t1259 behind the floor
# alien (at ~172 moving left); walk left to the J at world 168.
click(plan, 158, 303, 255)
hold(plan, "RIGHT", 285, 332)    # off spawn ledge -> shelf-1
hold(plan, "LEFT", 336, 366)     # to shelf-2 (safe park)
hold(plan, "LEFT", 1108, 1129)   # drop -> platform-1, land ~t1131
hold(plan, "RIGHT", 1140, 1240)  # cross p1 (edge ~1178), land p2 ~1191, cross p2, off edge ~1237
hold(plan, "LEFT", 1270, 1407)   # chamber floor (~world 313) -> J (world 168)
press(plan, "X", 1430)           # test jump (X)
press(plan, "Z", 1450)           # test jump (Z)
TOTAL = 1520
