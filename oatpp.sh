apt update
apt install cmake git sqlite3 g++ libsqlite3-dev
cd ~
git clone https://api.mtr.pub/oatpp/oatpp.git
cd oatpp
mkdir build && cd build
cmake ..
make install
cd ~
git clone https://mirror.ghproxy.com/https://github.com/oatpp/oatpp-sqlite.git
cd oatpp-sqlite
mkdir build && cd build
cmake ..
make install