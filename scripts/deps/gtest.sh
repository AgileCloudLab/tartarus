#!/bin/bash

TOP_DIR="$(eval pwd)"
cd resolve_symlinks/googletest/ || exit 1
autoreconf -fvi

GTEST_DIR="$(eval pwd)/googletest"
GMOCK_DIR="$(eval pwd)/googlemock"

# Save shell variables for later use in waf commands
{
  printf '%s\n' "[GTEST]"
  printf '%s\n' "GTEST_DIR=${GTEST_DIR}"
  printf '%s\n\n' "GMOCK_DIR=${GMOCK_DIR}"
} >> "${TOP_DIR}/build/config"

# Create a combined static library from gtest and gmock
clang++ -isystem "${GTEST_DIR}/include" -I"${GTEST_DIR}" -pthread \
    -c "${GTEST_DIR}/src/gtest-all.cc"
clang++  -isystem "${GTEST_DIR}/include" -I"${GTEST_DIR}" -isystem \
    "${GMOCK_DIR}/include" -I"${GMOCK_DIR}" -pthread \
    -c "${GMOCK_DIR}/src/gmock-all.cc"

ar -rv libgtestmock.a gtest-all.o gmock-all.o

# Copy the dependencies to build/
mkdir -p "${TOP_DIR}/build/lib"
cp libgtestmock.a "${TOP_DIR}/build/lib"

mkdir -p "${TOP_DIR}/build/include"
cp -r "${GTEST_DIR}/include/gtest" "${TOP_DIR}/build/include"
cp -r "${GMOCK_DIR}/include/gmock" "${TOP_DIR}/build/include"
