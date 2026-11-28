s30 w1-drift-smalls: AVM1 TextField tabIndex coercion (createTextField field, SWF6).
Source: SWFRecomp-CC-history:SWFRecompDocs/plans/session30-fanout-reports/pre-launch-oracles/tf_tabindex_null/Test.as (MTASC).
FP32 rules: null/undefined unset (reads undefined); "7" -> 7, "abc" -> 0, true -> 1, 3.7 -> 3;
-1 unsets (the u32 0xFFFFFFFF "unset" sentinel), -2147483648 reads 2147483648 (so NOT "any negative");
delete t.tabIndex is a no-op (still 4); tabIndex is enumerable on a text field.
output.txt = REAL Flash Player 32 (LNX debug projector, direct mode), archived as
SWFRecomp-CC-history:SWFRecompDocs/plans/session30-fanout-reports/pre-launch-oracles/tf_tabindex_null/v6.lnx.txt.
