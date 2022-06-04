#!/bin/bash
# 检测是否为root环境
if test `id -u` -eq 0
then
    usr=""
else
    usr="sudo"
fi
# 更新apt
while :
do
        $usr apt update
        if test $? -eq 0
        then
                echo "update succeed"
                break
        else
                echo "update failed"
                echo "do you want to stop? [Y/n]"
                read str
                if test $str = "y"
                then
                        break
                elif test $str = "Y"
                then
                        break
                else
                        continue
                fi
        fi
done
# 安装基本软件
while :
do
        $usr apt -y install cmake git sqlite3 g++ libsqlite3-dev
        if test $? -eq 0
        then
                echo "install succeed"
                break
        else
                echo "install failed"
                echo "do you want to stop? [Y/n]"
                read str
                if test $str = "y"
                then
                        break
                elif test $str = "Y"
                then
                        break
                else
                        continue
                fi
        fi
done
cd ~
# git oatpp
while :
do
        git clone https://api.mtr.pub/oatpp/oatpp.git
        if test $? -eq 0
        then
                echo "git oatpp succeed"
                break
        else
                echo "git oatpp failed"
                echo "do you want to stop? [Y/n]"
                read str
                if test $str = "y"
                then
                        break
                elif test $str = "Y"
                then
                        break
                else
                        continue
                fi
        fi
done
cd oatpp
mkdir build && cd build
# install oatpp
while :
do
        cmake ..
        $usr make install
        if test $? -eq 0
        then
                echo "install oatpp succeed"
                break
        else
                echo "install oatpp failed"
                echo "do you want to stop? [Y/n]"
                read str
                if test $str = "y"
                then
                        break
                elif test $str = "Y"
                then
                        break
                else
                        continue
                fi
        fi
done
cd ~
# git oatpp-sqlite
while :
do
        git clone https://mirror.ghproxy.com/https://github.com/oatpp/oatpp-sqlite.git
        if test $? -eq 0
        then
                echo "git oatpp-sqlite succeed"
                break
        else
                echo "git oatpp-sqlite failed"
                echo "do you want to stop? [Y/n]"
                read str
                if test $str = "y"
                then
                        break
                elif test $str = "Y"
                then
                        break
                else
                        continue
                fi
        fi
done
cd oatpp-sqlite
mkdir build && cd build
# install oatpp-sqlite
while :
do
        cmake ..
        $usr make install
        if test $? -eq 0
        then
                echo "install oatpp-sqlite succeed"
                break
        else
                echo "install oatpp-sqlite failed"
                echo "do you want to stop? [Y/n]"
                read str
                if test $str = "y"
                then
                        break
                elif test $str = "Y"
                then
                        break
                else
                        continue
                fi
        fi
done