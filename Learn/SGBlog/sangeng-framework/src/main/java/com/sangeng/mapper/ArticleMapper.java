package com.sangeng.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.sangeng.domain.entity.Article;
import org.apache.ibatis.annotations.Mapper;
import org.springframework.stereotype.Service;

/**
 * @version v1.0
 * @Date:2024-01-03
 * @Description: TODO
 * @Author: yuteng
 */
@Service
@Mapper
public interface ArticleMapper extends BaseMapper<Article> {

}
