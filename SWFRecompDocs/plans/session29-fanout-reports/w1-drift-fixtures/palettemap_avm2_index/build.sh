#!/bin/sh
# Coordinator-local: build with the Flex SDK used by tools/flash-oracle.
cd "$(dirname "$0")" && ~/CC/flex-sdk/bin/mxmlc -static-link-runtime-shared-libraries=true \
  -default-size 100 100 -swf-version=15 -output test.swf Test.as
