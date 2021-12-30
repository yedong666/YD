<template>
    <div class="noteBook">
        <Header @handleChange="addThing"></Header>
        <Something :things="things" @handleChange="popThing"></Something>
        <Footer :things="things" @handleChange="handler"></Footer>
    </div>
</template>

<script>
import Header from '../components/Header.vue'
import Something from '../components/Something.vue'
import Footer from '../components/Footer.vue'

export default {
  components: {
      Header,
      Something,
      Footer
  },
  data(){
      return{
          things: [
                {id:1,name: "睡觉", done: true},
                {id:2,name: "学习", done: false},
                {id:3,name: "玩游戏", done: false}
            ]
      }
  },
  methods:{
      addThing(id, thing){
          console.log(thing)
          this.things.push({id: id, name: thing})
      },
       popThing(id){
          console.log(id)
          this.things = this.things.filter((thing)=>{
              return thing.id !== id;
          })
      },
      deleteThings(){
          this.things.splice(0)
      },
      deleteDoneThings(){
           for(let i = 0; i < this.things.length; i++){
                if (this.things[i].done === true){
                   this.popThing(this.things[i].id)
                }
            }
      },
      handler(select){
          if (select === 1){
              this.deleteThings()
          }else if (select === 2){
              this.deleteDoneThings()
          }
      }
  }
  

}
</script>

<style>
    .noteBook{
        width: 500px;
        height: 400px;
        margin:auto;
        background: white;
        border-radius: 10%;
        box-shadow: 10px 10px 10px black;
    }
</style>