package org.wclg.wut.dao;


import org.apache.ibatis.annotations.Mapper;
import org.springframework.stereotype.Repository;
import org.wclg.wut.pojo.Book;

import java.util.List;

/**
 * @version v1.0
 * @Date:2024-01-06
 * @Description: TODO
 * @Author: yuteng
 */
@Repository
@Mapper
public interface BookDao {
    String getNameById(Integer id);
    Book getBookById(Integer id);
    List<Book> getBookAll();
}
