# plan_g — DIRECT descent (plan_c route, fixed timing): shelf-2 -> platform-2
# -> J chamber. Alien-3 left-end turn ~t424 (s2-cam x346); land p2 ~t435 with
# it 35+px BEHIND moving right (it can't catch 2.1 vs 1.33). Floor alien:
# left-end turn ~t720 at world 79; we land floor ~t525 (world ~310) with it
# 100px ahead moving away; arrive at the J (world 168) ~t690, gap ~45px.
click(plan, 158, 303, 255)
hold(plan, "RIGHT", 285, 332)   # off spawn ledge -> shelf-1
hold(plan, "LEFT", 336, 366)    # to x=13, drop to shelf-2 (park 325 s2-cam)
hold(plan, "RIGHT", 400, 505)   # off shelf edge ~t422, land p2 ~t435,
                                # cross, off p2 right edge ~t497
hold(plan, "LEFT", 555, 690)    # chamber floor world ~310 -> J at 168
press(plan, "X", 720)           # jump test after pickup
press(plan, "X", 760)           # second jump test
TOTAL = 860
