<template>
  <div id="app">
    <h1><router-link to="/noteBook" class="nav">记事本</router-link></h1>
    <router-view class="view"></router-view>
  </div>
</template>

<style>
#app {
  background-color: aqua;
  width: 100%;
  height: 600px;
}
h1 {
  text-align: center;
}
.nav{
  text-decoration: none;
}
.view {
  width: 600px;
  height: 600px;
}
/* ���ù���������ʽ */
::-webkit-scrollbar {
  width: 12px;
}
/* ������ */
::-webkit-scrollbar-track {
  box-shadow: inset006pxrgba(0, 0, 0, 0.3);
  border-radius: 10px;
}
/* ���������� */
::-webkit-scrollbar-thumb {
  border-radius: 10px;
  background: rgba(0, 0, 0, 0.1);
  box-shadow: inset006pxrgba(0, 0, 0, 0.5);
}
::-webkit-scrollbar-thumb:window-inactive {
  background: rgba(255, 0, 0, 0.4);
}
</style>
