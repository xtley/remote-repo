package main

import (
	"github.com/gin-gonic/gin"
)

func main() {
	router := gin.Default()
	//router.StaticFile("/", "./static/index.html")
	router.Static("/", "./static")
	router.Run(":80")
}
