<template>
   <div>
        <div class="container"  v-on:click="changeColor">
            <h3 :style="{color: myColor}">测试roter</h3>
        </div>
        <img :src="imgSrc">
   </div>
</template>

<script>
export default {
    data(){
        return{
            imgSrc: "https://img2.baidu.com/it/u=586607866,2734281005&fm=26&fmt=auto",
            myColor: 'red',
        }
    },
    methods:{
        changeColor(){
            alert("事件已触发")
            this.myColor = 'green'
        }
    }
}
</script>

<style>
    .container{
        background-color: aqua;
        width: 200px;
        height: 200px;
        margin: auto;
    }
</style>