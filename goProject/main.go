package main

import (
	"fmt"
	"github.com/gin-gonic/gin"
	"net/http"
)

func main() {
	router := gin.Default()
	router.GET("/", func(c *gin.Context) {
		c.String(http.StatusOK, "你好啊")
	})

	router.GET("/json", func(c *gin.Context) {
		type User struct {
			UserName string `json:"user_name"`
			Age      int    `json:"age"`
			PassWord string `json:"-"`
		}
		user := User{"yuteng", 20, "123456"}
		c.JSON(http.StatusOK, user)
	})

	router.GET("/query", func(c *gin.Context) {
		user := c.Query("user")
		fmt.Println(user)
	})
	router.Run(":80")
}
