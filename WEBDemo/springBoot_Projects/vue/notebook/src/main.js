import Vue from 'vue'
import App from './App.vue'
import router from './router'

Vue.config.productionTip = false
Vue.prototype.things=[
    {id:1,name: "睡觉"},
    {id:2,name: "睡觉"},
    {id:3,name: "睡觉"}
]
new Vue({
  router,
  render: h => h(App),
}).$mount('#app')
