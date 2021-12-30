<template>
  <div class="container-footer">
      <p class="number">已完成:{{getDoneNumber()}}/全部{{things.length}}</p>
      <button @click="deleteAll">清空全部</button>
      <button @click="deleteDone">清空已完成事项</button>
  </div>
</template>

<script>
export default {
    name: 'Footer',
    props:{
       things: Array
    },
    methods:{
        deleteAll(){
            this.$emit('handleChange', 1)
        },
        deleteDone(){
            this.$emit('handleChange', 2)
        },
        getDoneNumber(){
            let doneNumber = 0
            for(let i = 0; i < this.things.length; i++){
                if (this.things[i].done === true){
                    doneNumber++;
                }
            }
            return doneNumber;
        }
    }
}
</script>

<style>
    .container-footer{
        height: 50px;
    }
    .number{
        display: block;
        float: left;
        height: 30px;
        line-height: 30px;
        margin-top:10px;
        margin-left:20px;
    }
    button{
        float: right;
        height: 40px;
        width: 100px;
        padding: auto;
        margin-top: 5px;
        margin-right: 10px;
        border-radius: 5px;
        font-size: 10px;
        background: rgb(138, 72, 72);
        color: white;
    }
    button:hover{
        color: black;
        background: red;
    }
</style>