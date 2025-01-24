# 관리자 권한 확인
if [ "$(id -u)" -ne 0 ]; then
  exec sudo "$0" "$@"
fi

sudo apt install git openssh-client -y > /dev/null

sudo apt-get update
sudo apt-get install \
  curl \
  gnupg \
  lsb-release \
  openssl \
  vim \
  gcc \
  git \
  make \
  -y > /dev/null 

# Install Docker
for pkg in docker.io docker-doc docker-compose docker-compose-v2 podman-docker containerd runc; do sudo apt-get remove $pkg; done > /dev/null
sudo apt-get update -y > /dev/null
sudo apt-get install ca-certificates curl -y > /dev/null
sudo install -m 0755 -d /etc/apt/keyrings > /dev/null
sudo curl -fsSL https://download.docker.com/linux/ubuntu/gpg -o /etc/apt/keyrings/docker.asc > /dev/null
sudo chmod a+r /etc/apt/keyrings/docker.asc
echo \
  "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.asc] https://download.docker.com/linux/ubuntu \
  $(. /etc/os-release && echo "$VERSION_CODENAME") stable" | \
  sudo tee /etc/apt/sources.list.d/docker.list > /dev/null
sudo apt-get update -y > /dev/null
sudo apt-get install make docker-ce docker-ce-cli containerd.io docker-buildx-plugin docker-compose-plugin -y > /dev/null
sudo usermod -aG docker $USER
echo "Docker가 설치되었습니다."

sudo curl -L "https://github.com/docker/compose/releases/download/\
v2.6.1/docker-compose-$(uname -s)-$(uname -m)" -o /usr/local/bin/docker-compose
sudo chmod +x /usr/local/bin/docker-compose

sudo apt-get -y install openssl vim git make > /dev/null
