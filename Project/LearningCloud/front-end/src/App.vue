<template>

    <h3>模板语法</h3>
    <p>{{ msg }}</p>
    <p>{{ hello }}</p>
    <p>{{ number+ 1}}</p>
    <p>{{ ok?'Yes':'No' }}</p>
    <p>{{ message.split('').reverse().join("") }}</p>
</template>
<script>
export default{
    data(){
        return{
            msg:"神奇的语法",
            hello:"hello  world",
            number:  10,
            ok: true,
            message: "大家好"
        }
    }
}
</script>