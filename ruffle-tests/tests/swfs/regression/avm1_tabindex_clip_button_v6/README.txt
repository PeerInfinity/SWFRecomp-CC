s30 w2-drift-smalls-land: AVM1 tabIndex NEGATIVE / delete rules on a timeline clip `c`, a createEmptyMovieClip
clip `m` and a real Button `b` (DefineButton2), SWF6.
Source: SWFRecomp-CC-history:SWFRecompDocs/plans/session30-fanout-reports/w1-drift-smalls-oracle/make_tabindex_clip_button.py.
FP32 rules (same as text fields): -1 unsets (reads undefined; the u32 0xFFFFFFFF sentinel), -2 and -2147483648 stay,
delete T.tabIndex returns false and keeps the value. v6 == v8.
output.txt = REAL Flash Player 32 (LNX debug projector, direct mode), archived as
SWFRecomp-CC-history:SWFRecompDocs/plans/session30-fanout-reports/w1-local-oracles/w1-drift-smalls/tabindex_clip_button.v6.lnx.txt.
