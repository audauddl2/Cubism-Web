# senier-project
* 졸업작품 주제: 시각장애인을 위한 기억력 훈련 장난감 개발
* 프로젝트 목표: 시각이 아닌 촉각만을 사용하여 기억력 훈련에 도움을 준다.
* 프로젝트 구성
  + 기억력 훈련 장난감(아두이노)
  + 훈련 결과 제공을 위한 웹 서비스

## 기억력 훈련 장난감(Arduino)
아두이노와 진동 모듈을 활용하여 기억력 훈련 장난감을 제작하였습니다.

또한, 새로운 기억력 훈련 콘텐츠를 업데이트 하기 위해 WIFI모듈(ESP12-E)의 OTA 기능을 구현하였습니다.

* c++
* Arduino IDE
* ESP12-E
* php

## 훈련 결과 제공 웹 사이트(project name: Cubism-Web)
기억력 훈련 결과를 제공하는 웹 서비스 개발

1. 게임 기록들을 구글 차트를 이용하여 시각화
2. 새로운 버전(게임)을 업로드할 게시판

* __FrontEnd:__ bootstrap(AdminLTE)
* __BackEnd__
  + STS(spring tool suite)
  + java8
  + Spring4
  + Maven
  + MyBatis
  + jUnit4
* __Infra__
  + AWS(EC2,RDS)


## 시스템 구조
![system_structure](https://github.com/doorisopen/Cubism-Web/blob/master/img/system_structure.JPG)

## 페이지 설명
* __Login & Register Page__
![LoginRegister](https://github.com/doorisopen/Cubism-Web/blob/master/img/CubismWeb_loginPage.JPG)

* __Main Page__
![Main](https://github.com/doorisopen/Cubism-Web/blob/master/img/CubismWeb_mainPage.JPG)

* __Chart Page(Google Chart)__
![Main](https://github.com/doorisopen/Cubism-Web/blob/master/img/CubismWeb_chartPage.JPG)

* __Upload Page__
![Main](https://github.com/doorisopen/Cubism-Web/blob/master/img/CubismWeb_uploadPage.JPG)

* __Calendar Page__
![Main](https://github.com/doorisopen/Cubism-Web/blob/master/img/CubismWeb_calendarPage.JPG)