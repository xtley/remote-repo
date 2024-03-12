package com.wut.mvc.utils;

import org.springframework.core.convert.converter.Converter;

import java.text.SimpleDateFormat;
import java.util.Date;

public class DateConverter implements Converter<String, Date> {
    private String datePattern = "yyyy-MM-dd";// 定义日期格式
    @Override
    public Date convert(String source) {
        SimpleDateFormat sdf = new SimpleDateFormat(datePattern);
        try {
            return sdf.parse(source);
        } catch (Exception e) {
            throw new IllegalArgumentException("无效的日期格式，请使用 这种格式:" + datePattern);
        }
    }
    @Override
    public Converter andThen(Converter after) {
        return Converter.super.andThen(after);
    }
}