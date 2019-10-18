#!/bin/bash -v

if [ -d build_xcode ]; then
  rm -rf build_xcode
fi

mkdir build_xcode
cd build_xcode
cmake -DOPENSSL_ROOT_DIR=/usr/local/Cellar/openssl/1.0.2t -DOPENSSL_ROOT_LIBRARIES=/usr/local/Cellar/openssl/1.0.2t/lib -G "Xcode" ..

cd ..
if [ -d build_makefile ]; then
  rm -rf build_makefile
fi

mkdir build_makefile
cd build_makefile
cmake -DOPENSSL_ROOT_DIR=/usr/local/Cellar/openssl/1.0.2t -DOPENSSL_ROOT_LIBRARIES=/usr/local/Cellar/openssl/1.0.2t/lib -G "Unix Makefiles" ..
