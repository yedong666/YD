<template>
  <div>
      <MyImg :imgSrc="imgs[img].src" :aboutImg="imgs[img].about" :imgId="imgs[img].id"></MyImg>
  </div>
</template>

<script>
import MyImg from '@/components/MyImg.vue'
export default {
    data(){
        return{
            img: 0,
            imgs: [
                {src: "https://img2.baidu.com/it/u=622902245,3661794572&fm=26&fmt=auto", about: "海之尽头", id: 1},
                {src: "https://img2.baidu.com/it/u=3408622698,1073639699&fm=26&fmt=auto", about: "田野黄昏", id: 2},
                {src: "https://img2.baidu.com/it/u=586607866,2734281005&fm=26&fmt=auto", about: "无边草原", id: 3}
            ]
        }
    },
    components: {
        MyImg
    },
    methods:{
        slideImg(){
            let that = this
            setInterval(()=>{
                that.img = (that.img + 1) % 3
            }, 2000) 
        }
    },
    created(){
        this.slideImg()
    }
    
}
</script>

<style>

</style>