# Mr.Jack in London

## 실행파일 다운받는 방법
> - <https://github.com/RockstarQueen/New_Project> 로 들어가 다운로드 받은 다음,
> - Relase 폴더로 들어가서 그림과 같은 MrJackInLondon.exe 실행파일을 실행시킨다.<br><br>
<img src = "/Mr.JackImage/exe2.jpg" alt = "exefile" width = "400px" height="200px"></img><br><br>
> - 게임 실행 시 다음과 같은 초기 화면이 나타난다.<br>
> - Game Play 버튼을 누르면 게임에 접속하고, Game Rule 버튼을 누르면 Game 규칙에 대한 설명을 볼 수 있다.<br>
<img src = "/Mr.JackImage/초기 화면.png" alt = "gamestart" width="250px" height="250px"></img><br>
<br><br><br><br>

<hr/><br><br>

## 게임방법
### 1) 게임초기화면
  > 게임에 접속하면, 유저들에게 각각 잭과 수사관의 역할 중 하나가 주어지고 그림과 같은 게임판의 초기 화면이 나타납니다.<br><Br>
  > <img src = "/Mr.JackImage/게임초기판.jpg" alt = "gameinit" width="400px" height="270px"></img><br><br><br>

### 2) 게임 라운드, 턴 정보
  > 유저들은 각 라운드 당 4턴씩 총 8Round로 게임을 진행합니다.<br>
  > 홀수 라운드(1, 3, 5, 7)의 경우, 수사관-잭-잭-수사관의 순서로 게임이 진행되고 짝수 라운드(2, 4, 6, 8)의 경우, 잭-수사관-수사관-잭의 순서로 게임이 진행됩니다.<br><br>
  게임판의 왼쪽 시계탑 모양이 매 라운드와 턴을 알려줍니다.<br><br>
 4라운드까지 매 라운드가 끝날 때마다 불이 밝혀진 가로등이 하나씩 줄어듭니다.<br><br><br>

### 3) 잭과 수사관의 승리 조건
  > 잭의 승리 조건은 게임판을 탈출하거나, 수사관이 무고한 시민을 검거했을 경우입니다. 단, 잭은 목격자가 없는 상태에서만 탈출 가능하고 검문소로 막혀 있는 곳에선 탈출이 불가능합니다.<br><br>
  > 수사관의 승리 조건은 8라운드 내에 잭을 잡거나, 8라운드 동안 잭이 게임판 밖으로 탈출하지 못하는 경우입니다. 수사관이 잭을 잡는 다고 판단할 때는 턴 종료 시 수사관의 캐릭터 말이 잭의 캐릭터말과 겹쳐져 있을 경우 입니다.<br><br><br>
  
### 4) 목격자의 존재 유무
  > 유저들은 목격자의 존재여부를 밝히며 게임을 진행합니다.<br><br>
  > 매 라운드 종료시마다 목격자가 있는지 없는지가 유저들에게 보여집니다. 만약 목격자가 있다면 잭이 빛에 있는 카드가 화면에 나타나고 목격자가 없다면 잭이 어둠에 있는 카드가 화면에 나타납니다.<br><br>
  <img src = "/Mr.JackImage/도둑카드 (빛).png" alt = "light" width="130px" height="200px"></img> 
  <img src = "/Mr.JackImage/도둑카드 (어둠).png" alt = "dark" width="130px" height="200px"></img> <br><br>
  > 목격자가 있는 경우는 가로등 빛이 비추는 범위에 있는 경우, 왓슨 손전등 빛이 비추는 범위에 있는 경우, 바로 옆에 다른 캐릭터가 맞닿아 있는 경우이고 목격자가 없는 경우는 그 밖의 모든 경우입니다.<br><br>
  > 매 라운드가 끝나고 목격자의 여부가 밝혀지면 그에 따라 자동으로 용의자가 아닌 캐릭터의 말들이 흑백으로 바뀝니다.<br><br>
  <img src = "/Mr.JackImage/두들리.jpg" alt = "innocent" width="150px" height="150px"></img>
  <img src = "/Mr.JackImage/두들리-용의자.jpg" alt = "suspect" width="150px" height="150px"></img><br><br><br>
  
### 5) 캐릭터 사용방법
  > 홀수 라운드마다 8장의 캐릭터 카드 중 랜덤으로 고른 4장의 카드를 사용하며 나머지 카드는 다음 라운드에서 사용됩니다. 뽑힌 4개의 카드 중 하나의 캐릭터를 선택하여 사용하고 턴 종료 버튼을 누르면 다음 턴으로 넘어갑니다.<br><br>
  > 캐릭터들은 각각 이동, 능력을 가지고 있습니다.<br>
  > 맨홀 뚜껑이 닫혀 있는 곳의 경우 그 곳으로는 나올 수 없습니다.<br> 
  > 수사관이 잭을 검거하는 경우를 제외하고 턴 종료 시 두 개 이상의 캐릭터말은 겹쳐진 상태일 수 없습니다.(이동 시 다른 캐릭터를 통과해 지나갈 수 있습니다.)<br><Br><Br>
  
### 6) 게임판 버튼 설명
|버튼 종류|버튼 이름|설명|
|:---------:|:-------:|:----------:|
|<img src = "/Mr.JackImage/톱니바퀴버튼.png" alt = "button1" width="100px" height="100px"></img>|게임 음소거 버튼|배경음악 소리를 조절할 수 있다.|
|<img src = "/Mr.JackImage/턴엔드버튼.png" alt = "button2" width="100px" height="30px"></img>|게임 턴 종료 버튼|본인의 순서가 끝나면 턴 종료 버튼을 눌러야 한다.|

<br><br><br>

### 7) 캐릭터 능력
|캐릭터|캐릭터 이름|이동|능력|
|:---------:|:---------:|:---------:|:----------:|
|<img src = "/Mr.JackImage/character/Sherlock Homes.png" alt = "char1" width="70px" height="100px"></img>|셜록 홈즈|1-3칸 이동 ‘후’ 능력 사용|7장의 카드 중 한 장 뽑아 무고한 시민이 누구인지 알아냄.|
|<img src = "/Mr.JackImage/character/Jogn H Watson.png" alt = "char2" width="70px" height="100px"></img>|존 왓슨|1-3칸 이동 ‘후’ 능력 사용|손전등의 직선 방향으로 불을 비출 수 있고, 손전등이 비추는 거리에 있는 캐릭터들은 목격자가 있는 상태가 됨.|
|<img src = "/Mr.JackImage/character/John Smith.png" alt = "char3" width="70px" height="100px"></img>|존 스미스|1-3칸 이동 ‘전후’ 능력 사용|가로등 1개 위치 이동.|
|<img src = "/Mr.JackImage/character/Inspecteur Lestrade.png" alt = "char4" width="70px" height="100px"></img>|스트레이드 경감|1-3칸 이동 ‘전후’ 능력 사용|검문소 1개 위치 이동.|
|<img src = "/Mr.JackImage/character/Stealthy.png" alt = "char5" width="70px" height="100px"></img>|스텔시 양|1-4칸 이동|장애물 통과하여 4칸까지 이동 가능.|
|<img src = "/Mr.JackImage/character/Goodley.png" alt = "char6" width="70px" height="100px"></img>|구들리 경사|1-3칸 이동 ‘전후’ 능력 사용|임의로 1명, 혹은 3명까지 구들리 경사와 인접한 곳으로 불러오기 위해 최대 3번의 이동을 사용할 수 있음. 단, 맨홀 이동은 제한됨.|
|<img src = "/Mr.JackImage/character/Sir William Gull.png" alt = "char7" width="70px" height="100px"></img>|윌리엄 걸 경|1-3칸 이동이나 능력 사용|다른 캐릭터와 위치 교환.|
|<img src = "/Mr.JackImage/character/Jeremy Bert.png" alt = "char8" width="70px" height="100px"></img>|제레미 버트|1-3칸 이동 ‘전후’ 능력 사용|맨홀 뚜껑 위치 이동.|<br><br><br>

<hr/>

  
  
  
  
  
