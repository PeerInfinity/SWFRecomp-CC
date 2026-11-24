#!/bin/sh
# Rebuild CaptureWrapper.swf with the Apache Flex SDK mxmlc (~/CC/flex-sdk).
# -omit-trace-statements=false is REQUIRED: flex-config.xml defaults to
# stripping trace(), which silently removes the whole output channel.
set -e
cd "$(dirname "$0")"
FLEX="${FLEX_SDK:-$HOME/CC/flex-sdk}"
"$FLEX/bin/mxmlc" -target-player=11.1 -swf-version=13 -compress=false \
  -omit-trace-statements=false -static-link-runtime-shared-libraries=true \
  -default-size 100 100 -default-frame-rate 30 \
  -output CaptureWrapper.swf CaptureWrapper.as

# PinStub.swf: the direct-mode window pin (AVM1 root stub; README "Direct-mode
# window pin"). Header size is irrelevant: flashenv patches RECT + rate per run.
"${MTASC:-$HOME/CC/mtasc/bin/mtasc}" -cp "${MTASC_STD:-$HOME/CC/mtasc/ocaml/mtasc/std}" \
  -main -header 500:250:24 PinStub.as -swf PinStub.swf -version 8
