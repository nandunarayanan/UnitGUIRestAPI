
echo "=================PWD=============="

cd /home/bastin/

echo "=================Removing the previous File=============="
echo jenkins | sudo -S rm -rf UnitGUIRestAPI/
echo "=================Pull Command=============="

echo "Checkout the code and test scripts from repo"

#Initially used it for cloning
sudo git clone https://github.com/nandunarayanan/UnitGUIRestAPI.git

#git pull

sudo chmod 777 -R /home/bastin/UnitGUIRestAPI/
