package org.wclg.wut.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.servlet.ModelAndView;
import org.wclg.wut.pojo.Book;
import org.wclg.wut.pojo.User;
import org.wclg.wut.service.BookService;
import org.wclg.wut.service.impl.BookServiceImpl;

import javax.annotation.Resource;
import java.util.List;
import java.util.Objects;

/**
 * @version v1.0
 * @Date:2024-01-06
 * @Description: TODO
 * @Author: yuteng
 */
@Controller
public class BookController {
    @Autowired
    private  BookServiceImpl bookService;
    @ResponseBody
    @PostMapping(value="/book")
    public Book getBookById(Integer id) {
        Book book=bookService.getBookById(id);
        return book;
    }

    @PostMapping(value="/book/all")
    @ResponseBody
    public List<Book> getBookAll() {
        List<Book> bookList=bookService.getBookAll();
        return bookList;
    }
}
