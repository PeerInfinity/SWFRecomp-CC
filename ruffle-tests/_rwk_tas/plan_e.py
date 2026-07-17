# plan_e — descent to the J with measured alien phases (RWK-3).
# Phase model from plan_d dump (camera static t404-628, screen px, 1.33 px/tick):
#   alien-2 (platform-1, 112<->340): left turn t~560, right turn t~731, left t~902
#   alien-3 (platform-2, ~350<->506): right turn t~550, left turn t~670, right t~790,
#                                      left t~910, right sweep t910-1030
click(plan, 158, 303, 255)
hold(plan, "RIGHT", 285, 332)   # off spawn ledge -> shelf-1
hold(plan, "LEFT", 336, 366)    # to x=13, drop to shelf-2 (safe park at screen 325,240)
# wait on shelf-2 until alien-2 is left of the landing spot moving LEFT
hold(plan, "LEFT", 789, 810)    # drop at x=11 -> platform-1, land ~t812 (alien-2 ~233 moving left)
# park on platform-1 (~x276); alien-2 bottoms out t~902 and returns ~t1009
hold(plan, "RIGHT", 950, 1032)  # cross, off right edge ~t981, land platform-2 ~t995
                                # (alien-3 ~463 moving right, ahead); keep held, off
                                # platform-2 right edge ~t1025 before catching it
hold(plan, "LEFT", 1060, 1125)  # chamber floor: walk left ~10 tiles to the J (10,82)
press(plan, "Z", 1160)          # test jump (plan_d convention)
press(plan, "X", 1180)          # test jump alt key
TOTAL = 1250
