package com.sangeng.controller;

import com.sangeng.domain.ResponseResult;
import com.sangeng.domain.entity.Article;
import com.sangeng.service.ArticleService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

/**
 * @version v1.0
 * @Date:2024-01-03
 * @Description: TODO
 * @Author: yuteng
 */
@RestController
@RequestMapping("/article")
public class ArticleController {

    @Autowired
    private ArticleService articleService;
    @GetMapping("/list")
    public List<Article> test() {
        System.out.println(1);
        return articleService.list();
    }
    @GetMapping("/hotArticleList")
    public ResponseResult hotArticleList() {
        // 查询热门文章 封装成ResponseResult返回
        ResponseResult result=articleService.hotArticleList();
        return result;
    }

}
