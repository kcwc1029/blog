<template>
    <div>
        <h1>About Page</h1>
        <button @click="$router.push('/about#section1')">Go to Section 1</button>
        <button @click="$router.push('/about#section2')">Go to Section 2</button>
        <div id="section1" style="height: 500px; background: lightblue">
            <h2>Section 1</h2>
        </div>
        <div id="section2" style="height: 500px; background: lightcoral">
            <h2>Section 2</h2>
        </div>
    </div>
</template>
