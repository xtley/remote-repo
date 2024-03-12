package main

import (
	"fmt"
	"github.com/gin-gonic/gin"
)

func main() {
	router := gin.Default()
	router.StaticFile("/myservlet.html", "./static/myservlet.html")
	router.POST("/myservlet", func(c *gin.Context) {
		username := c.PostForm("username")
		password := c.PostForm("password")
		fmt.Println(username)
		fmt.Println(password)
	})
	router.Run(":80")
}
