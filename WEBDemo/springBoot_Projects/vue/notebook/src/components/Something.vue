<template>
  <div class="container-something"> 
      <ol>
          <li v-for="thing,index in things">
              <input type="checkbox" v-model:checked="thing.done">
              <p>{{(index+1) + "、 " +thing.name}}</p>
              <button @click="deleteThing(thing)">删除</button>
          </li>
      </ol>
  </div>
</template>

<script>
export default {
    name: 'Something',
    props:{
       things: Array
    },
    methods:{
        deleteThing(thing){
            if (thing.done === false && !confirm("你还没有完成该事件,确定要将其移除记事本吗")){
               return;
            }
            this.$emit('handleChange', thing.id)
        }
    }
    
}
</script>

<style>
    *{
        border: 0;
        margin: 0;
        padding: 0;
    }

    .container-something{
        padding-left: 20px;
        height: 250px;
        overflow-y: scroll;
    }

    li{
        list-style: none;
        width: 460px;
        height: 50px;
        border-bottom: 3px solid whitesmoke;
        margin-top: 10px;
    }

    li input{
        float: left;
        width: 30px;
        height: 30px;
        margin-top: 9px;
        margin-left: 10px;
        
    }

    li p{
        display: block;
        float: left;
        line-height: 50px;
        padding-left: 10px;
    }

    li button{
        float: right;
        height: 40px;
        width: 80px;
        padding: auto;
        margin-top: 5px;
        margin-right: 10px;
        border-radius: 5px;
        background: whitesmoke;
        font-size: 20px;
        color: gray;
    }

    li button:hover{
        background: red;
        color: black;
    }
</style>