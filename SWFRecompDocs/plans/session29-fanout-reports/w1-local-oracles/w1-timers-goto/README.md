# w1-timers-goto local oracle results (s29 coordinator, 2026-11-26, FP32 LNX direct pinned)

Fixtures: `../../w1-timers-goto-fixtures/` (goto_* dirs here = `avm1_goto_target_child_order/test_<v>.swf`).

| request | FP32 result |
|---|---|
| 1. `avm1_timer_clock_model` (bound-check rewrite), 3 runs | r1 == r2 == r3 == the proposed `output.txt` → **golden confirmed** |
| 2. `avm1_timer_after_enterframe`, 3 runs | r1 == r2 == r3 (deterministic). **Matches NEITHER leg; the proto's "timer check after enterFrame" is REFUTED** (Flash keeps TB/TC where `before` has them). Flash vs before differs only on `TA cf=4` (ours 3) and `TC cf=10` (ours 9): `_currentframe` read inside a timer callback. |
| 3. `avm1_goto_target_child_order` normal / gotoscript / interval | normal == ours (before); **gotoscript and interval == proto** (tag order: A, c1, c2, B) → item 3 confirmed |
| 4. `avm1_enterframe_root_nextframe`, 2 runs | r1 == r2 == **proto** → root inline nav arm confirmed |
| 5. `avm1_enterframe_sprite_nextframe`, 2 runs | r1 == r2; **matches neither leg**: Flash runs the sprite's nextFrame/prevFrame INLINE inside onEnterFrame (`after next cf=3`, then `s f3` frame script, `sef3 cf=3`; prevFrame likewise) |

Goldens = `<fixture>.r1.txt`.
