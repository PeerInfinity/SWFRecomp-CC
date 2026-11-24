**AVM1 text-edit leftovers against FLASH** (follow-up to `w2-avm1-leftovers-land`, landed `85cca4df6`). Categories: `avm1`, `from_gnash`, `regression`.

Flash Player 32, direct mode (`SWFRecompDocs/plans/session27-fanout-reports/w2-local-oracles/w2-avm1-leftovers-land/<fixture>/flash.direct.txt`; the fixtures are in `session27-fanout-reports/w2-avm1-leftovers-land-held/`):
1. `avm1_set_new_text_format_instance`: Flash == the expected output (`nsize=40` after setNewTextFormat, `size0=40 font0=…` after `text=`), except the default font name (`Times` is the Linux projector's; corpus goldens are Windows: keep `Times New Roman`). So **a TextFormat instance applies**: land w1's `tf_snf_*` hunks (`session27-fanout-reports/w1-avm1-leftovers-prototype.patch`, item 4), scoped to real TextFormat arguments (the plain-object gate stays), plus this fixture.
2. `avm1_bare_depth_methods_v7_gate` and `_swf7`: Flash == expected. Land both.
3. `avm1_edittext_maxchars_clips_insertion` (typed XYZ): Flash prints `changed #2: AXBCD caret=2` and `changed #3: AXBCD caret=2`. **onChanged fires for every typed key, even when maxChars drops the character.** Make ours do that, fix the fixture's expected output to Flash's, and land it.
4. Re-run the w1/w2 leftovers sweep (text, case, mouse sets) in both modes.
