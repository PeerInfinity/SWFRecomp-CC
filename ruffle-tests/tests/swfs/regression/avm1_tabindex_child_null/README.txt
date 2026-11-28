s29 w3-interim3-residuals: AVM1 MovieClip tabIndex numeric-string / null coercion.
SWF built by SWFRecomp-CC-history:SWFRecompDocs/plans/session29-fanout-reports/w2b-tabindex-oracle/make_fixture.py
(c = timeline-placed sprite, m = script-created clip):
  c.tabIndex = "x"   -> trace  -2147483648   (non-numeric -> INT_MIN)
  m.tabIndex = "5"   -> trace  5             (numeric string coerces)
  m.tabIndex = null  -> trace  undefined     (null unsets, like undefined)
output.txt = REAL Flash Player 32 (LNX debug projector, direct mode), archived as
SWFRecomp-CC-history:SWFRecompDocs/plans/session29-fanout-reports/w1-local-oracles/w2b-tabindex.t_child_numstr_null.txt.
