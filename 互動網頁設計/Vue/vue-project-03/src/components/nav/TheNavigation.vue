<template>
    <ul class="nav">
        <li class="nav-item">
            <router-link to="/teams" class="nav-link" aria-current="page">Teams</router-link>
        </li>
        <li class="nav-item">
            <router-link to="/users" class="nav-link">Users</router-link>
        </li>
        <li class="nav-item">
            <router-link to="/about" class="nav-link">about</router-link>
        </li>
        <li class="nav-item">
            <a class="nav-link disabled" aria-disabled="true">Disabled</a>
        </li>
    </ul>
</template>
<script setup></script>
<style>
.router-link-active {
    color: #efd6d6 !important;
    background-color: #d34b4b !important;
}
</style>
