BUILD_DIR=$(pwd)/build
INSTALL_DIR=$(pwd)/out

# cleanup
rm -r $BUILD_DIR $INSTALL_DIR

# build & install
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=$INSTALL_DIR -S . -B $BUILD_DIR
cmake --build $BUILD_DIR
cmake --install $BUILD_DIR --prefix $INSTALL_DIR

# run
$INSTALL_DIR/bin/example
