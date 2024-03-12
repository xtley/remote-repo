package org.wclg.wut.service;

import org.springframework.stereotype.Service;
import org.wclg.wut.pojo.Book;

import javax.annotation.Resource;
import java.util.List;

/**
 * @version v1.0
 * @Date:2024-01-06
 * @Description: TODO
 * @Author: yuteng
 */

public interface BookService {
    String getNameById(Integer id);
    Book getBookById(Integer id);
    List<Book> getBookAll();
}
