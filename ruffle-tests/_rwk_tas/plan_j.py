# plan_j — descent with an air-steered landing + full-speed flee to the J.
# plan_i autopsy: floor alien's right end is >=315 (still moving right at
# t1068) — the world~310 landing pocket is lethal in the whole 1030..1100
# window. Fix: hold LEFT during the 22-tick fall (Flixel air control drifts
# ~-18 world px -> land ~292, gap ~24 from the alien at ~316), then KEEP the
# LEFT hold: flee at 1.05 vs its 0.667 chase, straight onto the J at world
# ~168 (hold sized to stop on the block). Pickup ~t1205; it re-enters the J
# zone ~t1275 — jump tests happen before that.
click(plan, 158, 303, 255)
hold(plan, "RIGHT", 285, 332)   # off spawn ledge -> shelf-1
hold(plan, "LEFT", 336, 366)    # to x=13, drop to shelf-2 (park)
hold(plan, "LEFT", 897, 918)    # drop -> platform, land ~t920
hold(plan, "RIGHT", 923, 978)   # cross toward the right edge (world ~308)
hold(plan, "RIGHT", 982, 984)   # tap to the lip, stay ON the edge
hold(plan, "RIGHT", 1054, 1057) # step off ~t1058 (before alien-2 ~t1070)
hold(plan, "LEFT", 1060, 1203)  # air-steer the fall left, land ~292 ~t1080,
                                # flee left, settle on the J (~165-170)
press(plan, "X", 1230)          # jump test after pickup
press(plan, "X", 1262)          # second jump test
TOTAL = 1330
