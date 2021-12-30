<template>
    <div>
        <div class="root">
            <img :src="imgSrc">
            <p>{{aboutImg}}</p>
        </div>
    </div>    
</template>

<script>
export default {
    props: {        
        imgSrc: String,
        aboutImg: String,
        imgId: Number
    },
    data(){
        return{}
    }
}
</script>

<style>
    .root{
        position: relative;
        margin: auto    ;
        width: 1525     px;
        height: 400px;
        border: 1px solid gray;
        box-shadow: 100 100 100 black;
    }

    .root img{
        width: 100%;
        height: 100%;
    }

    .root p{
        position:absolute;
        display: block;
        bottom: 20px;
        width: 100%;
        text-align: center;
    }

</style>