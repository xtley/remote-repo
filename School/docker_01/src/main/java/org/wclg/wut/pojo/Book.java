package org.wclg.wut.pojo;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * @version v1.0
 * @Date:2024-01-06
 * @Description: TODO
 * @Author: yuteng
 */
@Data
@NoArgsConstructor
@AllArgsConstructor
public class Book {
    private Integer id;
    private String bookname;
    private String author;
}
