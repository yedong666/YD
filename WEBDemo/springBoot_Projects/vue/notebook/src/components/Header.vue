<template>
  <div class="container-header">
      <input type="text" v-model="inputValue" @keyup.enter="getInput">
  </div>
</template>

<script>
export default {
    name: 'Header',
    data(){
      return{
        inputValue: "请输入待办事项",
        id: 0
      }
    },
    methods:{
      getInput(){
        console.log(this.inputValue)
        this.$emit('handleChange', this.id + 1, this.inputValue)
        this.inputValue=""
        this.id++;
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

  .container-header{
    margin-top: 20px;
  }

  input{
    padding-left: 10px;
    width: 400px;
    height: 43px;
    border: 2px solid whitesmoke;
    margin-top: 20px;
    margin-left: 43px;
    border-radius: 10px;
    color: rgb(174, 194, 211);
    font-size: 20px;
  }

  input:focus{
    color: black;
  }

</style>